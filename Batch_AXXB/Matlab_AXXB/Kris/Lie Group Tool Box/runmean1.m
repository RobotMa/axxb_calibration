function [y]=runmean1(x,n)
%Author: Kristopher Reynolds
%[y]=runmean1(x,n)
%This function computes the running average of a data set "x", by
%convolving it with a window of length "n"
runmeanwin=ones(1,n)./n;
y=conv(x,runmeanwin);
y=y(1:end-(n-1));