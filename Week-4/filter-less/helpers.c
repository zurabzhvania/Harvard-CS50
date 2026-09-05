#include "helpers.h"
#include <math.h>

// Convert image to grayscale

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            int avg = (image[i][k].rgbtRed + image[i][k].rgbtGreen + image[i][k].rgbtBlue) / 3.0;
            image[i][k].rgbtRed = avg;
            image[i][k].rgbtGreen = avg;
            image[i][k].rgbtBlue = avg;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            int sepiaRed = round(
                image[i][k].rgbtRed * 0.393 +
                image[i][k].rgbtGreen * 0.769 +
                image[i][k].rgbtBlue * 0.189
            );

            int sepiaGreen = round(
                image[i][k].rgbtRed * 0.349 +
                image[i][k].rgbtGreen * 0.686 +
                image[i][k].rgbtBlue * 0.168
            );

            int sepiaBlue = round(
                image[i][k].rgbtRed * 0.272 +
                image[i][k].rgbtGreen * 0.534 +
                image[i][k].rgbtBlue * 0.131
            );

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][k].rgbtRed = sepiaRed;
            image[i][k].rgbtGreen = sepiaGreen;
            image[i][k].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width / 2; k++)
        {
            RGBTRIPLE temp = image[i][k];
            image[i][k] = image[i][width - 1 - k];
            image[i][width - 1 - k] = temp;
        }
    }
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            int pixelcount = 0;
            int greenTotal = 0;
            int blueTotal = 0;
            int redTotal = 0;

            for (int row = i - 1; row <= i + 1; row++)
            {
                for (int col = k - 1; col <= k + 1; col++)
                {
                    if (row >= 0 && row < height &&
                        col >= 0 && col < width)
                    {
                        redTotal += image[row][col].rgbtRed;
                        greenTotal += image[row][col].rgbtGreen;
                        blueTotal += image[row][col].rgbtBlue;
                        pixelcount++;
                    }
                }
            }

            temp[i][k].rgbtRed = round((float) redTotal / pixelcount);
            temp[i][k].rgbtGreen = round((float) greenTotal / pixelcount);
            temp[i][k].rgbtBlue = round((float) blueTotal / pixelcount);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            image[i][k] = temp[i][k];
        }
    }
    return;
}
