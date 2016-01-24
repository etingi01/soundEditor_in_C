# soundEditor_in_C

This project allows the edit of sound files: .wav.
Five main functions are implemented but there are 3 more functions that are implemented for practice purposes.

* Type the command "make all" in the command line of terminal.

* Type the command: $as5 <-option> sound1.wav [ sound2.wav sound3.wav ...]

5 main options:

* -list : The header information of the sound files is shown on the screen.

* -mono : The sterephonic sound files are converted to monophonic

* -chop : A new .wav file is created which contains only the sound between two defined seconds.
For example: ./as5 -chop sound1.wav 2 6
This will create a .wav file with the sound between the 2nd and 6th seconds of the sound1.wav

* -reverse : This option allows the reverse of the track. The result is stored in a new file called "new-{soundfile}.wav

* -similarity : This option tracks the similarity between two sound files. The calculation is based on two algorithms:
the euclidean matching and the Longest Common Subsequence. 

Three more options:

* -ep : This option accepts only 2 sound files. Using this option, the two files are merged in one file and you can here
it playing concurrently.

* -pro : This option accepts only 1 sound file. Then, this file is copied but the new one has several pauses in the sound.

* -enal : This option accepts only 2 sound files. It create a new file where the two sounds are playing alternately.


