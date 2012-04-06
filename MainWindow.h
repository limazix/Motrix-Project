#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

#include <gtk-3.0/gtk/gtk.h>
#include "default.h"

class MainWindow {
public:
   	MainWindow(int*, char***);
    MainWindow(const MainWindow& orig);
    virtual ~MainWindow();
    void init();
	GtkWidget* getWindow();
private:
	GtkWidget* window;
};

#endif	/* MAINWINDOW_H */
