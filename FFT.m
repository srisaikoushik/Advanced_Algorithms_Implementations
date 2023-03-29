% take two polynomials in coefficient array form
A = [-100,100,200,11,11];
B = [1,40];

% resize size of array which aligns with 2^(k) form
n = 1;
a = size(A);
b = size(B);
while n<(a(1,2)+b(1,2)-1)
    n = bitshift(n,1);
end

A = [A,zeros(1,n-a(1,2))];
B = [B,zeros(1,n-b(1,2))];

% calculate vals of polynomials at nth roots of unity

A1 = fft(A,n,0);
B1 = fft(B,n,0);

% calculate product of polynomials at nth roots of unity
C1 = A1.*B1;

% inverse fft the values to coefficent and rescale the values
C = fft(C1,n,1)*(1/n);

real(C)

% fft implementation (here if inv = 1, it implements the inverse transform
function Q = fft(A,n,inv)
   if n==1
       Q = A;
   else
       % nth root of unity
       w = exp(2*pi*1i/n);
       if inv == 1
         w = 1/w;
       end

       % recursive step
       Q1 = fft(A(1:2:end),n/2,inv);
       Q2 = fft(A(2:2:end),n/2,inv);

       Q = zeros(1,n);
       for j=1:(n/2)
           Q(1,j) = Q1(1,j) + w^(j-1)*Q2(1,j);
           Q(1,(j+n/2)) = Q1(1,j) - w^(j-1)*Q2(1,j);
       end
   end

end
