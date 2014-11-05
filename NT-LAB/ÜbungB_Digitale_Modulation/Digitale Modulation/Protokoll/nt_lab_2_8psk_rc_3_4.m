
%8PSK
rb = 2048000
M = 8
Rc = 3/4
a = 1

snn = [12 12.5 13 13.5 14 15];

snr_db = 10*log10(10.^(snn/10) -1);
snr = 10.^(snn/10)-1;

rs = rb/(log2(M) * Rc)
Bn = rs
B = Bn * (1+a)

Eb_N0 = snr_db * Bn/rb;

BER = [1 1 5.3*10^-3 5.3*10^-5 5.61*10^-7 0];