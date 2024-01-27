#include "helpers.h"
#include <math.h>
#include <stdint.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0 ; i < height; i++)
    {
        for(int j = 0 ; j < width ; j++)
        {
           int average = round (( image[i][j].rgbtGreen + image[i][j].rgbtRed + image[i][j].rgbtBlue ) / 3.0 );
            image[i][j].rgbtGreen = average ;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtBlue = average ;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0 ; i < height; i++)
    {
        for(int j = 0 ; j < (width/2) ; j++)
        {
          int x =  image[i][j].rgbtGreen ;
          image[i][j].rgbtGreen = image[i][(width-1)-j].rgbtGreen;
          image[i][(width-1)-j].rgbtGreen = x ;

          int y =  image[i][j].rgbtRed ;
          image[i][j].rgbtRed = image[i][(width-1)-j].rgbtRed;
          image[i][(width-1)-j].rgbtRed = y ;

          int z =  image[i][j].rgbtBlue ;
          image[i][j].rgbtBlue = image[i][(width-1)-j].rgbtBlue;
          image[i][(width-1)-j].rgbtBlue = z ;


        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //creationg a copy of the originalimage
    RGBTRIPLE copyimage[height][width] ;

    for(int i = 0 ; i < height; i++)
    {
        for(int j = 0 ; j < width ; j++)
        {
         copyimage[i][j].rgbtRed =image[i][j].rgbtRed ;
         copyimage[i][j].rgbtBlue =image[i][j].rgbtBlue ;
         copyimage[i][j].rgbtGreen =image[i][j].rgbtGreen ;

        }
    }
   int Redavg;
   int Greenavg;
   int Blueavg ;
    //blur the image
    for(int i = 0 ; i < height; i++)
    {
        for(int j = 0 ; j < width ; j++)
        {
            if(i == 0 && j == 0 )
            {
                Redavg = round ((image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed )/4.0);
                Greenavg = round ((image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen )/4.0);
                Blueavg = round ((image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue )/4.0);
            }
            else if(i == (height-1)&& j == 0)
            {
                 Redavg = round ((image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed )/4.0);
                 Greenavg = round ((image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen )/4.0);
                 Blueavg = round ((image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue )/4.0);
            }
            else if(i == 0 && j == width-1)
            {
                 Redavg = round ((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed )/4.0);
                 Greenavg = round ((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen )/4.0);
                 Blueavg = round ((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue )/4.0);
            }
            else if(i == height-1 && j == width-1)
            {
                 Redavg = round ((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed )/4.0);
                 Greenavg = round ((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen )/4.0);
                 Blueavg = round ((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue )/4.0);
            }
            else if(i == 0)
            {
                Redavg = round ((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j+1].rgbtRed  )/6.0);
                Greenavg = round ((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen)/6.0);
                Blueavg = round ((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue)/6.0);
            }
            else if(i == height-1)
            {
                Redavg = round ((image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed  )/6.0);
                Greenavg = round ((image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen)/6.0);
                Blueavg = round ((image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue)/6.0);
            }
            else if(j == 0)
            {
                Redavg = round ((image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i+1][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j+1].rgbtRed + image[i+1][j+1].rgbtRed  )/6.0);
                Greenavg = round ((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i+1][j+1].rgbtGreen)/6.0);
                Blueavg = round ((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i+1][j+1].rgbtBlue)/6.0);
            }
            else if(j == width-1)
            {
                Redavg = round ((image[i][j].rgbtRed + image[i-1][j].rgbtRed + image[i+1][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j-1].rgbtRed + image[i+1][j-1].rgbtRed  )/6.0);
                Greenavg = round ((image[i][j].rgbtGreen + image[i-1][j].rgbtGreen + image[i+1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i+1][j-1].rgbtGreen)/6.0);
                Blueavg = round ((image[i][j].rgbtBlue + image[i-1][j].rgbtBlue + image[i+1][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i+1][j-1].rgbtBlue)/6.0);
            }
            else
            {
                Redavg = round ((image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed)/9.0);
                Greenavg = round ((image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/9.0);
                Blueavg = round ((image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue)/9.0);
            }

                copyimage[i][j].rgbtRed = Redavg  ;
                copyimage[i][j].rgbtGreen =  Greenavg  ;
                copyimage[i][j].rgbtBlue =   Blueavg  ;
        }
    }
    for(int i = 0 ; i < height; i++)
    {
        for(int j = 0 ; j < width ; j++)
        {
         image[i][j].rgbtRed = copyimage[i][j].rgbtRed;
         image[i][j].rgbtBlue = copyimage[i][j].rgbtBlue;
         image[i][j].rgbtGreen = copyimage[i][j].rgbtGreen ;
        }
    }

}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //creationg a copy of the originalimage
    RGBTRIPLE copyimage[height][width] ;

    for(int i = 0 ; i < height; i++)
    {
        for(int j = 0 ; j < width ; j++)
        {
         copyimage[i][j].rgbtRed =image[i][j].rgbtRed ;
         copyimage[i][j].rgbtBlue =image[i][j].rgbtBlue ;
         copyimage[i][j].rgbtGreen =image[i][j].rgbtGreen ;

        }
    }
   int RedGX;
   int GreenGX;
   int BlueGX ;

   int RedGY;
   int GreenGY;
   int BlueGY ;


    //blur the image
    for(int i = 0 ; i < height; i++)
    {
        for(int j = 0 ; j < width ; j++)
        {
            if(i == 0 && j == 0 )
            {

                RedGX = 0*image[i][j].rgbtRed + 2*image[i][j+1].rgbtRed + 0*image[i+1][j].rgbtRed + 1*image[i+1][j+1].rgbtRed ;
                RedGY = 0*image[i][j].rgbtRed + 0*image[i][j+1].rgbtRed + 2*image[i+1][j].rgbtRed + 1*image[i+1][j+1].rgbtRed ;

                GreenGX = 0*image[i][j].rgbtGreen + 2*image[i][j+1].rgbtGreen +0* image[i+1][j].rgbtGreen + 1*image[i+1][j+1].rgbtGreen ;
                GreenGY = 0*image[i][j].rgbtGreen + 0*image[i][j+1].rgbtGreen + 2*image[i+1][j].rgbtGreen + 1*image[i+1][j+1].rgbtGreen ;


                BlueGX = 0*image[i][j].rgbtBlue + 2*image[i][j+1].rgbtBlue + 0*image[i+1][j].rgbtBlue +1* image[i+1][j+1].rgbtBlue ;
                BlueGY = 0*image[i][j].rgbtBlue + 0*image[i][j+1].rgbtBlue + 2*image[i+1][j].rgbtBlue +1* image[i+1][j+1].rgbtBlue ;

            }
            else if(i == (height-1)&& j == 0)
            {
                 RedGX = 0*image[i][j].rgbtRed +2* image[i][j+1].rgbtRed + 0*image[i-1][j].rgbtRed + 1*image[i-1][j+1].rgbtRed;
                 RedGY = 0*image[i][j].rgbtRed +0* image[i][j+1].rgbtRed + (-2)*image[i-1][j].rgbtRed + (-1)*image[i-1][j+1].rgbtRed ;

                 GreenGX = 0*image[i][j].rgbtGreen +2* image[i][j+1].rgbtGreen +0* image[i-1][j].rgbtGreen +1* image[i-1][j+1].rgbtGreen;
                 GreenGY = 0*image[i][j].rgbtGreen +0* image[i][j+1].rgbtGreen + (-2)*image[i-1][j].rgbtGreen +(-1)* image[i-1][j+1].rgbtGreen;

                 BlueGX = 0*image[i][j].rgbtBlue +2* image[i][j+1].rgbtBlue +0* image[i-1][j].rgbtBlue +1* image[i-1][j+1].rgbtBlue;
                 BlueGY = 0*image[i][j].rgbtBlue +0* image[i][j+1].rgbtBlue + (-2)*image[i-1][j].rgbtBlue + (-1)*image[i-1][j+1].rgbtBlue;
            }
            else if(i == 0 && j == width-1)
            {
                 RedGX = 0*image[i][j].rgbtRed + (-2)*image[i][j-1].rgbtRed +0* image[i+1][j].rgbtRed +(-1)* image[i+1][j-1].rgbtRed ;
                 RedGY = 0*image[i][j].rgbtRed +0* image[i][j-1].rgbtRed + 2*image[i+1][j].rgbtRed + 1*image[i+1][j-1].rgbtRed ;


                 GreenGX = 0*image[i][j].rgbtGreen + (-2)*image[i][j-1].rgbtGreen + 0*image[i+1][j].rgbtGreen +(-1)* image[i+1][j-1].rgbtGreen ;
                 GreenGY = 0*image[i][j].rgbtGreen + 0*image[i][j-1].rgbtGreen +2* image[i+1][j].rgbtGreen +1* image[i+1][j-1].rgbtGreen ;


                 BlueGX = 0*image[i][j].rgbtBlue +(-2)* image[i][j-1].rgbtBlue + 0*image[i+1][j].rgbtBlue +(-1)* image[i+1][j-1].rgbtBlue ;
                 BlueGY = 0*image[i][j].rgbtBlue + 0*image[i][j-1].rgbtBlue +2* image[i+1][j].rgbtBlue + 1*image[i+1][j-1].rgbtBlue ;
            }
            else if(i == height-1 && j == width-1)
            {
                 RedGX = 0*image[i][j].rgbtRed + (-2)*image[i][j-1].rgbtRed + 0*image[i-1][j].rgbtRed + (-1)*image[i-1][j-1].rgbtRed ;
                 RedGY = 0*image[i][j].rgbtRed + 0*image[i][j-1].rgbtRed + (-2)*image[i-1][j].rgbtRed + (-1)*image[i-1][j-1].rgbtRed ;


                 GreenGX = 0*image[i][j].rgbtGreen + (-2)*image[i][j-1].rgbtGreen +0* image[i-1][j].rgbtGreen +(-1)* image[i-1][j-1].rgbtGreen ;
                 GreenGY = 0*image[i][j].rgbtGreen +0* image[i][j-1].rgbtGreen + (-2)*image[i-1][j].rgbtGreen + (-1)*image[i-1][j-1].rgbtGreen ;

                 BlueGX = 0*image[i][j].rgbtBlue +(-2)* image[i][j-1].rgbtBlue +0* image[i-1][j].rgbtBlue +(-1)* image[i-1][j-1].rgbtBlue ;
                 BlueGY =0*image[i][j].rgbtBlue + 0*image[i][j-1].rgbtBlue +(-2)* image[i-1][j].rgbtBlue + (-1)*image[i-1][j-1].rgbtBlue ;

            }
            else if(i == 0)
            {
                RedGX = 0*image[i][j].rgbtRed + (-2)*image[i][j-1].rgbtRed +2* image[i][j+1].rgbtRed +0* image[i+1][j].rgbtRed +(-1)* image[i+1][j-1].rgbtRed +1* image[i+1][j+1].rgbtRed ;
                RedGY = 0*image[i][j].rgbtRed +0* image[i][j-1].rgbtRed + 0*image[i][j+1].rgbtRed +2* image[i+1][j].rgbtRed + 1*image[i+1][j-1].rgbtRed +1* image[i+1][j+1].rgbtRed ;


                GreenGX = 0*image[i][j].rgbtGreen + (-2)*image[i][j-1].rgbtGreen +2* image[i][j+1].rgbtGreen +0* image[i+1][j].rgbtGreen +(-1)* image[i+1][j-1].rgbtGreen + 1*image[i+1][j+1].rgbtGreen;
                GreenGY = 0*image[i][j].rgbtGreen +0* image[i][j-1].rgbtGreen +0* image[i][j+1].rgbtGreen +2* image[i+1][j].rgbtGreen + 1*image[i+1][j-1].rgbtGreen +1* image[i+1][j+1].rgbtGreen;


                BlueGX = 0*image[i][j].rgbtBlue +(-2)* image[i][j-1].rgbtBlue + 2*image[i][j+1].rgbtBlue +0* image[i+1][j].rgbtBlue + (-1)*image[i+1][j-1].rgbtBlue +1* image[i+1][j+1].rgbtBlue;
                BlueGY = 0*image[i][j].rgbtBlue +0* image[i][j-1].rgbtBlue +0* image[i][j+1].rgbtBlue +2* image[i+1][j].rgbtBlue + 1*image[i+1][j-1].rgbtBlue + 1*image[i+1][j+1].rgbtBlue;


            }
            else if(i == height-1)
            {
                RedGX = 0*image[i][j].rgbtRed + (-2)*image[i][j-1].rgbtRed + 2*image[i][j+1].rgbtRed +0* image[i-1][j].rgbtRed + (-1)*image[i-1][j-1].rgbtRed +1* image[i-1][j+1].rgbtRed  ;
                RedGY = 0*image[i][j].rgbtRed +0* image[i][j-1].rgbtRed + 0*image[i][j+1].rgbtRed + (-2)*image[i-1][j].rgbtRed +(-1)* image[i-1][j-1].rgbtRed +(-1)* image[i-1][j+1].rgbtRed  ;


                GreenGX = 0*image[i][j].rgbtGreen +(-2)* image[i][j-1].rgbtGreen + 2* image[i][j+1].rgbtGreen +0* image[i-1][j].rgbtGreen +(-1)* image[i-1][j-1].rgbtGreen + 1*image[i-1][j+1].rgbtGreen;
                GreenGY =0*image[i][j].rgbtGreen +0* image[i][j-1].rgbtGreen +0* image[i][j+1].rgbtGreen +(-2)* image[i-1][j].rgbtGreen +(-1)* image[i-1][j-1].rgbtGreen +(-1)* image[i-1][j+1].rgbtGreen;


                BlueGX =0*image[i][j].rgbtBlue +(-2)* image[i][j-1].rgbtBlue +  2*image[i][j+1].rgbtBlue +0* image[i-1][j].rgbtBlue +(-1)* image[i-1][j-1].rgbtBlue + 1*image[i-1][j+1].rgbtBlue;
                BlueGY = 0*image[i][j].rgbtBlue +0* image[i][j-1].rgbtBlue + 0*image[i][j+1].rgbtBlue + (-2)*image[i-1][j].rgbtBlue + (-1)*image[i-1][j-1].rgbtBlue +(-1)* image[i-1][j+1].rgbtBlue;


            }
            else if(j == 0)
            {
                RedGX =  0*image[i][j].rgbtRed +0* image[i-1][j].rgbtRed +0* image[i+1][j].rgbtRed +2* image[i][j+1].rgbtRed + 1*image[i-1][j+1].rgbtRed + 1*image[i+1][j+1].rgbtRed  ;
                RedGY =  0*image[i][j].rgbtRed +(-2)* image[i-1][j].rgbtRed +2* image[i+1][j].rgbtRed +0* image[i][j+1].rgbtRed + (-1)* image[i-1][j+1].rgbtRed +1* image[i+1][j+1].rgbtRed  ;


                GreenGX =  0*image[i][j].rgbtGreen +0* image[i-1][j].rgbtGreen +0* image[i+1][j].rgbtGreen +2*  image[i][j+1].rgbtGreen +1* image[i-1][j+1].rgbtGreen + 1*image[i+1][j+1].rgbtGreen;
                GreenGY =  0*image[i][j].rgbtGreen +(-2)* image[i-1][j].rgbtGreen +2* image[i+1][j].rgbtGreen +0* image[i][j+1].rgbtGreen + (-1)*image[i-1][j+1].rgbtGreen +1* image[i+1][j+1].rgbtGreen;


                BlueGX = 0*image[i][j].rgbtBlue + 0*image[i-1][j].rgbtBlue + 0*image[i+1][j].rgbtBlue + 2*image[i][j+1].rgbtBlue +1* image[i-1][j+1].rgbtBlue + 1*image[i+1][j+1].rgbtBlue;
                BlueGY =  0*image[i][j].rgbtBlue + (-2)*image[i-1][j].rgbtBlue +2* image[i+1][j].rgbtBlue +0* image[i][j+1].rgbtBlue + (-1)*image[i-1][j+1].rgbtBlue +1* image[i+1][j+1].rgbtBlue;


            }
            else if(j == width-1)
            {
                RedGX = 0*image[i][j].rgbtRed + 0*image[i-1][j].rgbtRed +0* image[i+1][j].rgbtRed +(-2)* image[i][j-1].rgbtRed +(-1)* image[i-1][j-1].rgbtRed +(-1)* image[i+1][j-1].rgbtRed  ;
                RedGY = 0*image[i][j].rgbtRed +(-2)* image[i-1][j].rgbtRed + 2*image[i+1][j].rgbtRed +0* image[i][j-1].rgbtRed +(-1)* image[i-1][j-1].rgbtRed + 1*image[i+1][j-1].rgbtRed  ;


                GreenGX = 0*image[i][j].rgbtGreen +0* image[i-1][j].rgbtGreen +0* image[i+1][j].rgbtGreen + (-2)*image[i][j-1].rgbtGreen +(-1)* image[i-1][j-1].rgbtGreen +(-1)* image[i+1][j-1].rgbtGreen;
                GreenGY =0*image[i][j].rgbtGreen +(-2)* image[i-1][j].rgbtGreen + 2*image[i+1][j].rgbtGreen +0* image[i][j-1].rgbtGreen +(-1)* image[i-1][j-1].rgbtGreen +1* image[i+1][j-1].rgbtGreen;


                BlueGX = 0*image[i][j].rgbtBlue + 0*image[i-1][j].rgbtBlue +0* image[i+1][j].rgbtBlue +(-2)* image[i][j-1].rgbtBlue +(-1)*  image[i-1][j-1].rgbtBlue +(-1)* image[i+1][j-1].rgbtBlue;
                BlueGY =0*image[i][j].rgbtBlue +(-2)* image[i-1][j].rgbtBlue +2* image[i+1][j].rgbtBlue +0* image[i][j-1].rgbtBlue +(-1)*  image[i-1][j-1].rgbtBlue +1* image[i+1][j-1].rgbtBlue;


            }
            else
            {
                RedGX = (-2) *image[i][j-1].rgbtRed +0* image[i][j].rgbtRed +2* image[i][j+1].rgbtRed + (-1)* image[i-1][j-1].rgbtRed +0* image[i-1][j].rgbtRed +1* image[i-1][j+1].rgbtRed + (-1)*image[i+1][j-1].rgbtRed +0* image[i+1][j].rgbtRed +1* image[i+1][j+1].rgbtRed;
                RedGY = 0*image[i][j-1].rgbtRed +0* image[i][j].rgbtRed +0*image[i][j+1].rgbtRed + (-1)*image[i-1][j-1].rgbtRed +(-2)* image[i-1][j].rgbtRed +(-1)* image[i-1][j+1].rgbtRed +1* image[i+1][j-1].rgbtRed + 2*image[i+1][j].rgbtRed +1* image[i+1][j+1].rgbtRed;


                GreenGX = (-2)*image[i][j-1].rgbtGreen +0* image[i][j].rgbtGreen +2* image[i][j+1].rgbtGreen +(-1)* image[i-1][j-1].rgbtGreen +0* image[i-1][j].rgbtGreen +1* image[i-1][j+1].rgbtGreen +(-1)* image[i+1][j-1].rgbtGreen +0*  image[i+1][j].rgbtGreen +1* image[i+1][j+1].rgbtGreen;
                GreenGY =0*image[i][j-1].rgbtGreen +0* image[i][j].rgbtGreen +0* image[i][j+1].rgbtGreen +(-1)* image[i-1][j-1].rgbtGreen +(-2)* image[i-1][j].rgbtGreen +(-1)* image[i-1][j+1].rgbtGreen +1* image[i+1][j-1].rgbtGreen +2* image[i+1][j].rgbtGreen +1* image[i+1][j+1].rgbtGreen;


                BlueGX = (-2)*image[i][j-1].rgbtBlue + 0*image[i][j].rgbtBlue +2* image[i][j+1].rgbtBlue +(-1)* image[i-1][j-1].rgbtBlue + 0*image[i-1][j].rgbtBlue + 1*image[i-1][j+1].rgbtBlue +(-1)* image[i+1][j-1].rgbtBlue +0* image[i+1][j].rgbtBlue +1* image[i+1][j+1].rgbtBlue;
                BlueGY = 0*image[i][j-1].rgbtBlue + 0*image[i][j].rgbtBlue +0* image[i][j+1].rgbtBlue +(-1)* image[i-1][j-1].rgbtBlue +(-2)* image[i-1][j].rgbtBlue +(-1)* image[i-1][j+1].rgbtBlue +1* image[i+1][j-1].rgbtBlue +2* image[i+1][j].rgbtBlue +1* image[i+1][j+1].rgbtBlue;


            }

               int red = round( sqrt((RedGX*RedGX)+(RedGY*RedGY))*1.0);
                int green  = round( sqrt((GreenGX*GreenGX)+(GreenGY*GreenGY))*1.0);
                int blue  =   round(sqrt((BlueGX*BlueGX)+(BlueGY*BlueGY))*1.0) ;


            copyimage[i][j].rgbtBlue  = (blue > 255) ? 255 : blue;
            copyimage[i][j].rgbtGreen = (green > 255) ? 255 : green;
            copyimage[i][j].rgbtRed = (red > 255) ? 255 : red;



        }
    }
    for(int i = 0 ; i < height; i++)
    {
        for(int j = 0 ; j < width ; j++)
        {
         image[i][j].rgbtRed = copyimage[i][j].rgbtRed;
         image[i][j].rgbtBlue = copyimage[i][j].rgbtBlue;
         image[i][j].rgbtGreen = copyimage[i][j].rgbtGreen ;
        }
    }
    return ;
}
