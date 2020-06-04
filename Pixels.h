/**
 * Class Pixels
 * Includes decomposition-recomposition of color bytes from
 * a vector of bytes (unsigned chars) which carries all the bytes of
 * an image data read from a Bmp file using lodepng class (.h, .cpp) from : http://lodev.org/lodepng/
 *
 * Usage:
 * 	Pixels colorPixels(image,width,height)
 * 	Image: image data in vector of bytes(unsigned char)
 * 	creates the Pixels object with dynamic memory allocation of matrices
 * 	red,green,blue and alpha with size [height][width],
 * 	height: number of rows, width: number of columns
 *
 * 	Modified versions are also used(redM,blueM,etc.) since in filtering operations
 * 	we would like to keep a copy of the original values
 *
 * 	After processing the data in these matrices one can recompose
 * 	color pixels in a similar image data (vector of unsigned chars) which
 * 	can further be written to a Png file using functions implemented in
 * 	the lodepng class
 * 	Ex (see lines 130-140 in processImage.cpp):
 * 		vector<unsigned char> newImage(w * h * 4);
 * 		colorPixels.recomposeColor(newImage);
 * 		vector<unsigned char> png;
 * 		lodepng::encode(png, newImage, w, h);
 * 		lodepng::save_file(png, pngFileName);
 *
 * 	Created for image processing exercises, Comp/Elec230
 * 	Baris Bozkurt, Spring 2016
 */
#ifndef PIXELS_H_
#define PIXELS_H_
#include <vector>
using namespace std;
//functions for avoiding saturation, i.e. keeping a color value in range 0-255
inline int MaxWith0(int x) {return (x > 0)? x : 0;}
inline int MinWith255(int x) {return (x > 255)? 255 : x;}

class Pixels{
public:
	Pixels(vector<unsigned char>& image,int w,int h):width(w),height(h){
		//dynamic allocation of two-dimensional arrays red, green, blue
		red=new uint8_t*[h];
		green=new uint8_t*[h];
		blue=new uint8_t*[h];
		alpha=new uint8_t*[h];
		for(int i=0;i<h;i++){
			red[i]=new uint8_t[w];
			green[i]=new uint8_t[w];
			blue[i]=new uint8_t[w];
			alpha[i]=new uint8_t[w];
		}
		//allocating memory for modified versions
		redM=new uint8_t*[h];
		greenM=new uint8_t*[h];
		blueM=new uint8_t*[h];
		alphaM=new uint8_t*[h];
		for(int i=0;i<h;i++){
			redM[i]=new uint8_t[w];
			greenM[i]=new uint8_t[w];
			blueM[i]=new uint8_t[w];
			alphaM[i]=new uint8_t[w];
		}
		setColors(image);
	}
	~Pixels(){
		//memory deallocation
		for(int i=0;i<height;i++){
			delete [] red[i];
			delete [] green[i];
			delete [] blue[i];
			delete [] alpha[i];
		}
		delete [] red;delete [] green;
		delete [] blue;delete [] alpha;
		//memory deallocation for modified versions
		for(int i=0;i<height;i++){
			delete [] redM[i];
			delete [] greenM[i];
			delete [] blueM[i];
			delete [] alphaM[i];
		}
		delete [] redM;delete [] greenM;
		delete [] blueM;delete [] alphaM;
	}
//function for copying bytes from the image vector into red, green, blue components/arrays
	void setColors(vector<unsigned char>& image){
		unsigned newpos;
		for(int i = 0; i < height; i++)
			for(int j = 0; j < width; j++)
			{
				newpos = 4 * i * width + 4 * j;
				red[i][j]=image[newpos];
				green[i][j]=image[newpos+1];
				blue[i][j]=image[newpos+2];
				alpha[i][j]=image[newpos+3];
			}
	}
	//recomposing image data from colors red, green and blue
	void recomposeColor(vector<unsigned char>& image){
		unsigned newpos;
		for(int i = 0; i < height; i++)
			for(int j = 0; j < width; j++)
			{
				newpos = 4 * i * width + 4 * j;
				image[newpos]=red[i][j];
				image[newpos+1]=green[i][j];
				image[newpos+2]=blue[i][j];
				image[newpos+3]=alpha[i][j];
			}
	}

	//Your code starts here
	//convolurion with a weight matrix(kernel) with dimensions [2*k+1][2*k+1]
	void convolve(double* w, int k){
			int side=2*k+1;int wx,wy;
			//finding normalization constant to adjust weights to a sum of 1
			double weightsSum=0,weight;
			for(int i=0;i<(2*k+1);i++){
				for(int j=0;j<(2*k+1);j++){
					weightsSum+=(*(w+i*side+j));//pointer version of w[i][j]
				}
			}
			for (int i=0; i<height; i++) {
				for (int j=0;j<width; j++) {
					if (i>k && j>k && i<(height-k) && j<(width-k)) {
						double sumRed=0;double sumGreen=0;double sumBlue=0;
						for (int x=i-k; x<=(i+k); x++) {
							for (int y=j-k; y<=(j+k); y++) {
								wx=x-i+k;wy=y-j+k;
								weight=*(w+wx*side+wy);//pointer version of w[wx][wy]
								sumRed+=red[x][y]*weight;
								sumGreen+=green[x][y]*weight;
								sumBlue+=blue[x][y]*weight;
							}
						}
						redM[i][j]=(uint8_t)MinWith255(MaxWith0((sumRed/weightsSum)));
						greenM[i][j]=(uint8_t)MinWith255(MaxWith0((sumGreen/weightsSum)));
						blueM[i][j]=(uint8_t)MinWith255(MaxWith0((sumBlue/weightsSum)));
					}else{
						redM[i][j]=red[i][j];
						greenM[i][j]=green[i][j];
						blueM[i][j]=blue[i][j];
					}
				}
			}
			copyModToOrg();
		}
	//Your code ends here
private:
	//pointer for two-dimensional color arrays
	uint8_t** red;
	uint8_t** green;
	uint8_t** blue;
	uint8_t** alpha;
	//modified versions
	uint8_t** redM;
	uint8_t** greenM;
	uint8_t** blueM;
	uint8_t** alphaM;
	int width,height;
	//copying modified data to original data matrices
	void copyModToOrg(){
		for (int i=0; i<height; i++)
			for (int j=0;j<width; j++) {
				red[i][j]=redM[i][j];green[i][j]=greenM[i][j];
				blue[i][j]=blueM[i][j];//alpha[i][j]=alphaM[i][j];
			}
	}

};


#endif /* PIXELS_H_ */
