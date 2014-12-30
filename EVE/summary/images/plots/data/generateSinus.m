%% Einfaches Beispielprogramm zum Erzeugen von Plots in LaTeX

phi = 0:0.05:2*pi;

figure; l = {};
plot(phi, sin(phi), 'r'); hold on; l = {l{:}, 'Sinus'};
plot(phi, cos(phi), 'g'); l = {l{:}, 'Cosinus'};
xlabel('t [s]');
ylabel('y [-]');

data = [phi', sin(phi'), cos(phi')]; % each column is one record
save 'sinus.dat' data -ascii -tabs;