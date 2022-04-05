#include <gtk/gtk.h>
#include "editorHeaders/ImageBMP.hpp"

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *image;
  GtkWidget *grid;
  GtkWidget *headerbar;


  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);




  
  
  grid = gtk_grid_new();
  gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  gtk_widget_set_halign(grid, GTK_ALIGN_CENTER );
  gtk_grid_set_row_homogeneous(GTK_GRID(grid), 1);
 
  gtk_window_set_child (GTK_WINDOW (window), grid);
  image = gtk_image_new_from_file("./image.bmp");
  gtk_grid_attach (GTK_GRID (grid), image, 0, 0, 8, 9);


  button = gtk_button_new_with_label ("Горизонтальный укур");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 0, 9, 1, 1);

    button = gtk_button_new_with_label ("Вертикальный укур");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 1, 9, 1, 1);

    button = gtk_button_new_with_label ("Повернуть туда");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 2, 9, 1, 1);

    button = gtk_button_new_with_label ("Повернуть обратно");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 3, 9, 1, 1);

    button = gtk_button_new_with_label ("Серенькое))");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 4, 9, 1, 1);

    button = gtk_button_new_with_label ("хз че");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 5, 9, 1, 1);

    button = gtk_button_new_with_label ("хз че");
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  gtk_grid_attach (GTK_GRID (grid), button, 6, 9, 1, 1);

  gtk_window_present (GTK_WINDOW (window));
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}
