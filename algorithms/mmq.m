% MMQ Matlab/Octave

m5 = [0 7.5 15 23 31 39.5 48.5 58.5 74.5];
m4 = [0 8 14.0 22.5 30.5 39.5 48 59 73];
m3 = [0 7 14.5 22.5 31 39.5 48 60 74.5];
m2 = [0 7.5 15 22.5 30.5 38.5 47.5 59.5 73.5];
m1 = [0 7.5 14 22 30.5 38 48 58 72];
m = (m1 + m2 + m3 + m4 + m5)/5;
o = [0 5 10 15 20 25 30 35 40];
 
o_rad = o .* (pi/180);
m_rad = m .* (pi/180);

sin_o1 = sin(o_rad); 
sin_o2 = sin(m_rad);

num = 0;
den = 0;
len = length(sin_o1);

avg_x = sum(sin_o1)/len;
avg_y = sum(sin_o2)/len;

for i = 1:len
	num = num + ((sin_o1(i) - avg_x)*(sin_o2(i) - avg_y));
	den = den + (sin_o1(i) - avg_x).^2;
end

b = num/den;
a =  avg_y - b * avg_x;

y = a + b * sin_o1;
plot(sin_o1,sin_o2,'.', sin_o1,y);
legend('Pontos experimentais ', 'Melhor reta ');
xlabel(' sin\theta_1 ');
ylabel(' sin\theta_2 ');
