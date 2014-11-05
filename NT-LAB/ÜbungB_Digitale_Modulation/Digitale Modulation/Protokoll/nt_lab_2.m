
%8PSK
rb = 2048000
M = 8
Rc = 7/8
a = 1

snn = [11 12 13 14 15 16]

snr_db = 10*log10(10.^(snn/10) -1)
snr = 10.^(snn/10)-1

rs = rb/log2(M)
Bn = rs
B = Bn * (1+a)

Eb_N0 = snr * B/rb

BER = [1 5.69*10^-2 3.57*10^-2 9.34*10^-5 0 0]