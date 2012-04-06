#include "MouseGUI.h"

MouseGUI::MouseGUI(GtkWidget* window) {
	this->window = window;
	gtk_window_set_title (GTK_WINDOW (this->window), "Mouse");
}

MouseGUI::MouseGUI(const MouseGUI& orig) {
}

MouseGUI::~MouseGUI() {
}

void MouseGUI::components(){
	GtkWidget* button;
	button = gtk_button_new_with_label ("Hello World");
	gtk_container_add (GTK_CONTAINER (this->window), button);
	gtk_widget_show (button);
}
