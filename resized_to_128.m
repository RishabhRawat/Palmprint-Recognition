%%Resize All the images in the folder to 128x128
files = dir('*.bmp');
filter = load('doublecrossingfilter.mat');
for file = files'
    tempImage = imread(file.name);
    tempImage = imresize(tempImage,[128 128]);
    imwrite(tempImage,strcat('R',file.name));
end
    