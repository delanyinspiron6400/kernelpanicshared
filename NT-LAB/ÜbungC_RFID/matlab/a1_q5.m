

dist = linspace(0,14,29);
dist = dist'
uss = [0.894 0.863 0.813 0.756 0.706 0.637 0.584 0.531 0.481 0.434 0.425 0.425 0.425 0.425 0.425 0.425 0.425 0.425 0.425 0.425 0.425 0.425 0.425 0.425 0.425 0.425 0.425 0.425 0.425]
uss = uss'
uind = uss / (sqrt(2)*2)  
fr = 13.56*10^6 %13.56 MHz
u0 = 4*pi*10^-7
ur = 1 %luft

A = 0.072*0.042 % 72mm x 42mm
hrms = uind / (2*pi * fr * u0 * ur * A)