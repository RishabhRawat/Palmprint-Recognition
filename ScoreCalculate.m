files = dir('*.bmp');
score = zeros(230*5 ,230*5);
A = zeros(128,128,1150);
for i = 1:1150
     A(:,:,i) = imread(files(i).name,'bmp');
end

heppy = 'LOAD_COMPLETE'

%% 
for i = 1:1150
    P = A(:,:,i);
    for j = 1:1150
        B = A(:,:,j);
        score(i,j) = Distance(P,B);
    end
    i
end
%% 

% %% SECTION TITLE
% % DESCRIPTIVE TEXT
% a = score < 0.45;
% stem(a)
% title(sum(a))