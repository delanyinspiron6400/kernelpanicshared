
%8PSK
rb = 2048000
M = 4
Rc = 7/8
a = 1

snn = [15 14 13 12 11.5 11];

snr_db = 10*log10(10.^(snn/10) -1);
snr = 10.^(snn/10)-1;

rs = rb/(log2(M) * Rc)
Bn = rs
B = Bn * (1+a)

Eb_N0 = snr_db * Bn/rb;

BER = [0 0 0 0 0 1];