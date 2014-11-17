
uss = [0.913 1.83 2.75 3.69 4.59 5.53]
uss = uss'
uind = uss / (sqrt(2)*2)  
fr = 13.56*10^6 %13.56 MHz
u0 = 4*pi*10^-7
ur = 1 %luft

A = 0.072*0.042 % 72mm x 42mm
hrms = uind / (2*pi * fr * u0 * ur * A)


hrms_iso = hrms.^(1.2)
hrms_iso = hrms_iso'
Upiso = 30 * 1 ./ (hrms_iso) / 1000

uppupper = [0.3206 0.86621 0.15851 0.2187 0.17537 0.3239]

upplower = [0.04195 0.72724 0.03235 0.31214 0.06154 0.26793]

