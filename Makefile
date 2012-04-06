#Para escrever comentários ##
############################# Makefile ##########################
CC=g++
SOUNDLIBS=-lrt -lasound -ljack -lpthread libportaudio.a
SPHINXLIBS=`pkg-config --cflags --libs sphinxbase pocketsphinx`
GTKLIBS=`pkg-config --cflags --libs gtk+-3.0`
SRC= main.cpp default.h VoiceRecognizer.cpp VoiceRecognizer.h MediaPlayer.cpp MediaPlayer.h MouseGUI.cpp MouseGUI.h MainWindow.cpp MainWindow.h

#-----> Distancia com o botao TAB ### e nao com espaços
all: motrix clean
motrix:  $(SRC)
	$(CC) -o $@ $^ -Wall $(SPHINXLIBS) $(GTKLIBS) $(SOUNDLIBS)

clean:
	rm -rf *.o
mrproper: clean
	rm -rf teste
