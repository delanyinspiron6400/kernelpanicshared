

freq = [12 12.2 12.4 12.6 12.8 13 13.2 13.25 13.3 13.35 13.4 13.45 13.5 13.55 13.6 13.65 13.7 13.75 13.8 14 14.2 14.4 14.6 14.8 15]
freq = freq'
uss = [0.5 0.575 0.6 0.813 0.844 0.869 0.887 0.894 0.9 0.906 0.906 0.906 0.913 0.913 0.913 0.919 0.925 0.925 0.925 0.925 0.925 0.919 0.906 0.9 0.887]
uss = uss'
uind = uss / (sqrt(2)*2)  
fr = 13.56*10^6 %13.56 MHz
u0 = 4*pi*10^-7
ur = 1 %luft

A = 0.072*0.042 % 72mm x 42mm
hrmsq5 = uind ./ (2*pi * freq * u0 * ur * A *10^6)