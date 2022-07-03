// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 3rd January 2021


// #########################
//     Header Section
// #########################
#include <gtk/gtk.h>
// Important: GTK compile 
//	$ gcc source_file_name `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`

// #########################
//   Definition Section
// #########################
static void print_hello (GtkWidget *widget, gpointer data){
  g_print ("Hello World\n");
}

static void start (GtkApplication *app, gpointer user_data){
  GtkWidget *window;
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 500, 600);


  GtkWidget *head = gtk_header_bar_new();
  gtk_header_bar_set_title(GTK_HEADER_BAR(head) , "Greetings");
  gtk_container_add(GTK_CONTAINER(window) , head);
  
  GtkWidget *button_box;
  button_box = gtk_button_box_new (GTK_ORIENTATION_VERTICAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  //GtkWidget *entry = gtk_entry_new_with_buffer("Enter the text here.");
  //gtk_container_add(GTK_CONTAINER())

	GtkWidget *frame;
	frame = gtk_frame_new("Youre Details");
	gtk_container_add(GTK_CONTAINER (button_box) , frame);
	
  GtkWidget *text;
  text = gtk_label_new("Greetings ! \n How are you bro.");
  //gtk_label_set_text(GTK_LABEL(text),"HIHIHIH");
  gtk_container_add(GTK_CONTAINER (frame) , text);
  
  GtkWidget *aa1;
  aa1 = gtk_spinner_new();
  gtk_spinner_start(GTK_SPINNER(aa1));
  gtk_container_add(GTK_CONTAINER (button_box) , aa1);

  GtkWidget *button;
  button = gtk_button_new_with_label ("Exit");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (button_box), button);

  gtk_widget_show_all (window);
}


// #########################
//       Main Section
// #########################


int main (int argc, char **argv){
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (start), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

