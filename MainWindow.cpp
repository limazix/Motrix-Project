#include "MainWindow.h"

MainWindow::MainWindow(int* argc, char*** argv) {

  gtk_init (argc, argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

}

MainWindow::MainWindow(const MainWindow& orig) {
}

MainWindow::~MainWindow() {
}

GtkWidget* MainWindow::getWindow(){
	return this->window;
}

void MainWindow::init(){

  gtk_widget_show (window);
  gtk_main ();

}
