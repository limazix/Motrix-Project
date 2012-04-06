#ifndef MOUSEGUI_H
#define	MOUSEGUI_H

#include <gtk-3.0/gtk/gtk.h>
#include "default.h"

class MouseGUI {
public:
    MouseGUI(GtkWidget* window);
    MouseGUI(const MouseGUI& orig);
    virtual ~MouseGUI();
	void components();
private:
	GtkWidget* window;
};

#endif	/* MOUSEGUI_H */
