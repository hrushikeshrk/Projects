

%--------Gender Recognition----------%

fs=8000;                      % Sampling rate
nbits=16;
nChannels=1;
duration=3;                 % Recording time 3 secs
arObj=audiorecorder(fs, nbits, nChannels);

fprintf("Press any key to start %g seconds of recording", duration); pause
fprintf("Recording");

recordblocking(arObj, duration);
fprintf("Finished recording.\n");

fprintf("Press any key to play the recording"); pause; 
fprintf("\n");
play(arObj);
fprintf("Plotting the waveform:\n");
y=getaudiodata(arObj);          % Get audio sample data
plot(y);             

%Autocorrelation

ms2 = fs/500;
ms20 = fs/50;
r = xcorr(y, ms20, "coeff");
d = (-ms20:ms20)/fs;
plot(d, r);
title("Autocorrelation");
xlabel("Delay (s)");
ylabel("Correlation coeff");
r = r(ms20 + 1 : 2*ms20+1);
[rmax, tx] = max(r(ms2:ms20));
 Fx = fs/(ms2+tx-1);

 

Fth= 160; % threshold frequency =160 Hz

if Fx> Fth
    disp("It is a female voice!")
else
    disp("It is a male voice!")

end
