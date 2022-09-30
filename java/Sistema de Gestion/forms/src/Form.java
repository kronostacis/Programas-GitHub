import javax.swing.*;
import javax.swing.plaf.ButtonUI;
import java.awt.*;
import java.awt.event.*;

public class Form extends JFrame {
    private static JLabel directionsLabel = new JLabel("ingresa tu nombre ");
    private static JLabel outputLabel = new JLabel();
    private static JTextField namebox = new JTextField(30);
    private static JButton button = new JButton("Click Here ");
    public static void main(String[] args) throws Exception {
        Form window = new Form();
        window.setSize(800, 600);
        window.setVisible(true);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // objetos a agregar 
        window.setLayout(new FlowLayout());
        window.getContentPane().add(directionsLabel);
        window.getContentPane().add(outputLabel);
        window.getContentPane().add(namebox);
        window.getContentPane().add(button);
    }
}
