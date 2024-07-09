#include "helpers.h"
#include "math.h"
#include "stdio.h"
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            // grayscale using the NTSC formula: 0.299*Red + 0.587*Green + 0.114*Blue
            double NTSC = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;

            image[i][j].rgbtRed = round(NTSC);
            image[i][j].rgbtGreen = round(NTSC);
            image[i][j].rgbtBlue = round(NTSC);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            // grayscale using the NTSC formula: 0.299*Red + 0.587*Green + 0.114*Blue
            double tr = 0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue;
            double tg = 0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue;
            double tb = 0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue;

            if (tr > 255){
                image[i][j].rgbtRed = 255;
            }else{
                image[i][j].rgbtRed = round(tr);
            }
            if (tg > 255){
                image[i][j].rgbtGreen = 255;
            }else{
                image[i][j].rgbtGreen = round(tg);
            }
             if (tb > 255){
                image[i][j].rgbtBlue = 255;
            }else{
                image[i][j].rgbtBlue = round(tb);
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copyOfArray[height][width];
    // Make new array picture
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            copyOfArray[i][j].rgbtRed = image[i][j].rgbtRed;
            copyOfArray[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copyOfArray[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    for (int iHeight = 0; iHeight < height; iHeight++){
        for (int j = 0, w = width - 1; j < width; j++, w--){
            image[iHeight][j].rgbtRed = copyOfArray[iHeight][w].rgbtRed;
            image[iHeight][j].rgbtGreen = copyOfArray[iHeight][w].rgbtGreen;
            image[iHeight][j].rgbtBlue = copyOfArray[iHeight][w].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int RADIUS = 1;
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int count = 0;

            for (int di = -RADIUS; di <= RADIUS; di++){

                for (int dj = -RADIUS; dj <= RADIUS; dj++){
                    int newI = di + i;
                    int newJ = dj + j;

                    if (newI >= 0 && newI < height && newJ >= 0 && newJ < width){
                        sumRed += copy[newI][newJ].rgbtRed;
                        sumGreen += copy[newI][newJ].rgbtGreen;
                        sumBlue+= copy[newI][newJ].rgbtBlue;
                        count++;
                    }
                }

            }
            image[i][j].rgbtRed = round(sumRed/(float)count);
            image[i][j].rgbtGreen = round(sumGreen/(float)count);
            image[i][j].rgbtBlue = round(sumBlue/(float)count);
        }
    }

    return;
}
