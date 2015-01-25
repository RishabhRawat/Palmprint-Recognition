%%Resize All the images in the folder to 128x128
files = dir('*.bmp');
threshold = 0.5;
for file = files'
    tempImage = imread(file.name);
    tempImage = im2bw(tempImage, threshold);
    imwrite(tempImage,strcat('b',file.name));
end
    