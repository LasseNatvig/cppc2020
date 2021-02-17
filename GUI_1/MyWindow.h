// MyWindow.h
#pragma once
#include "GUI.h"
#include "Graph.h"
using namespace Graph_lib;

struct MyWindow : Graph_lib::Window {
	MyWindow(Point topLeft, int w, int h, const string& title);
private:
	Button start_button;
	Button quit_button;
	Button end_button;

	string name;  // Stores title of window
	Menu colorMenu; // Menu from GUI.h is a collection of buttons

	In_box noOfDiscs;
	Vector_ref<Shape> discs;
	Out_box radius;

	static void cb_start(Address, Address); // callback for start_button
	static void cb_quit(Address, Address); // callback for quit_button
	static void cb_red(Address, Address); // callback for red_button
	static void cb_blue(Address, Address); // callback for blue_button
	static void cb_green(Address, Address); // callback for green_button
	static void cb_end(Address, Address); // callback for end_button

	void start(); // action to be done when start_button is pressed
	void quit() { cout << name + ": quit called\n"; hide(); } // action to be done when quit_button is pressed, placed inline. For hide(), see PPP page 567
	void end();  // removed color-menu
	void red_pressed();
	void blue_pressed();
	void green_pressed();

	void drawDiscs(Color color); // draw discs with given color
};