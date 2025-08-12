package myapp.main;

import myapp.utils.Helper;

public class MainApp {
    public static void main(String[] args) {
        System.out.println("MainApp running...");
        Helper.printMessage("Hello from sub-package!");
    }
}