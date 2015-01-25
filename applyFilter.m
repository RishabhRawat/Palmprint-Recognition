%%Resize All the images in the folder to 128x128
files = dir('*.bmp');
load('triplecrossingfilter.mat');
for file = files'
    tempImage = imread(file.name);
    tempImage = imfilter(tempImage,tripleCrossingFilter);
    tempImage = imcrop(tempImage,[12 12 127 127]);
    imwrite(tempImage,strcat('tcf',file.name));
end
    