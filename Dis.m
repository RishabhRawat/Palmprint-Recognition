function [ result ] = Dis( A, B,thresh )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here

% Ma = A > -1;
% Mb = B > -1;
% numerator = and(bitxor(A,B) > thresh,and(Ma,Mb));
% denominator = and(Ma,Mb);
% result = sum(sum(numerator))/sum(sum(denominator));

Ma = A > 0;
Mb = B > 0;

result = sum(sum(bitxor(A,B) > thresh))/(128*128);

%result = sum(sum(xor(A,B)))/(128*128);

end

