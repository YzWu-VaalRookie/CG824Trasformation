#include <stdio.h>
#include <stdlib.h>
#include "BMP_Structure.h"
#include "CGTDataStructure.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	char IPtxtfilename[350];
	char IPbmpfilename[350];
	char OPbmpfilename[350];
	
	BMPDataStructure *IP_BMPImg = (BMPDataStructure*)malloc(sizeof(BMPDataStructure));
	BMPDataStructure *OP_BMPGrey8bitImg = (BMPDataStructure*)malloc(sizeof(BMPDataStructure));
	
	ReadIPCoefficient("IOPtxt.txt", IPbmpfilename, OPbmpfilename);
	
	if(Read_BMPImgFile(IPbmpfilename, IP_BMPImg))
	{
		IP_BMPImg->BMPHeaderDataPtr->bPixel = bPiexl_0_Delete(IP_BMPImg->BMPHeaderDataPtr->biWidth,
															  IP_BMPImg->BMPHeaderDataPtr->biHeight,
															  IP_BMPImg->BMPHeaderDataPtr->bPixel,
                                                       		  IP_BMPImg->BMPHeaderDataPtr->biBitCount);
	}
	
	int imgwidth = IP_BMPImg->BMPHeaderDataPtr->biWidth;
	int imgheight = IP_BMPImg->BMPHeaderDataPtr->biHeight;
	
	Create_BMP_DS_Set54Header(OP_BMPGrey8bitImg, imgwidth, imgheight, 8, 1);
	GenerateColorMap_GrayScale8bits(OP_BMPGrey8bitImg->ColorMap); //OP_BMPGrey8bitImg Colormap allocation 
	
	if(IP_BMPImg->BMPHeaderDataPtr->biBitCount == 24)
        Img24CGTo8G(IP_BMPImg, OP_BMPGrey8bitImg); //24bits CG to 8bits Gray 
    else if(IP_BMPImg->BMPHeaderDataPtr->biBitCount == 8)
        Img8CGTo8G(IP_BMPImg, OP_BMPGrey8bitImg);  //8bits CG to 8bits Gray
    
    Write_BMPImgFile(OPbmpfilename, OP_BMPGrey8bitImg);
	printf("Write BMP Img File Success......\n");
	
	BMP_DS_free(OP_BMPGrey8bitImg);
	BMP_DS_free(IP_BMPImg);
	
	system("pause");
	return 0;
	
}
