// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 2nd January 2022

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Main{
	public static void main(String args[]){
		if(args.length == 0) {
			SwingUtilities.invokeLater(
				new Runnable(){
					public void run(){
						new GUIDemo();
					}
				}
			);
			
			System.out.println("No command line arguments. Switching to GUI !");
			return;
		}
		for (int i = 0 ; i < args.length ; i++){
			if (args[i].matches("-e")) Secure.lock(args[i+1]);
			if (args[i].matches("-d")) Secure.unlock(args[i+1]);
		}
	}

}

class Secure{
	public static String getEncryptKey(String str){
		String key = "";
		for (int i = 0 ; i < str.length() ; i++) 
			if(str.charAt(i) != '\n') key += (char)(str.charAt(i) + 3);
			else key += '`';
		return key;
	}
	
	public static String getDecryptKey(String str){
		String key = "";
		for (int i = 0 ; i < str.length() ; i++) 
			if(str.charAt(i) != '`') key += (char)(str.charAt(i) - 3);
			else key += '\n';
		return key;
	}
	
	public static void lock(String str){
		System.out.println("------------------------------");
		System.out.println("🔹️ Getting Encrypted key ... ");
		System.out.println("------------------------------");
		System.out.println();
		System.out.println(getEncryptKey(str));
		System.out.println();
		System.out.println("------------------------------");
	}
	
	public static void unlock(String str){
		System.out.println("------------------------------");
		System.out.println("🔹️ Getting Actual Massage ... ");
		System.out.println("------------------------------");
		System.out.println();
		System.out.println(getDecryptKey(str));
		System.out.println();
		System.out.println("------------------------------");
	}
	
}

class GUIDemo{
	GUIDemo(){
		// 1. Title
		JLabel title_label_01 = new JLabel("Secure It !",JLabel.CENTER);
		JLabel title_label_02 = new JLabel("Version 2.0.0",JLabel.CENTER);
		JLabel title_label_03 = new JLabel("Encryption and Decryption System",JLabel.CENTER);
		title_label_01.setFont(new Font("Verdana",Font.PLAIN,60));
		title_label_02.setFont(new Font("Verdana",Font.PLAIN,20));
		title_label_03.setFont(new Font("Verdana",Font.PLAIN,20));
		
		// 2. Source Text area
		JTextArea source_text = new JTextArea("Enter the massage here !" , 10 , 30);
		JScrollPane source_text_scrolling = new JScrollPane(source_text);
		source_text.setLineWrap(true);
		source_text.selectAll(); // Focus
		
		// 3. Result Text area
		JTextArea result_text = new JTextArea("Result will be here ! " , 10 , 30);
		JScrollPane result_text_scrolling = new JScrollPane(result_text);
		result_text.setLineWrap(true);
		result_text.setEditable(false); // can not edit
		
		// 4. Action Buttons
			// 1. Encrypt Button
		    JButton Encrypt = new JButton("Encrypt");
			Encrypt.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent ae){
					result_text.setText(Secure.getEncryptKey(source_text.getText()));
				}
			});
			// 2. Decrypt Button
		    JButton Decrypt = new JButton("Decrypt");
			Decrypt.addActionListener(new ActionListener(){
				public void actionPerformed(ActionEvent ae){
					result_text.setText(Secure.getDecryptKey(source_text.getText()));
				}
			});
			// 3. Group them !
			JPanel panel_01 = new JPanel();
		    panel_01.add(Encrypt);
		    panel_01.add(Decrypt);
		    
		// # Frame setup
		JFrame frame_01 = new JFrame("Encryption / Decryption");
		frame_01.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame_01.setLayout(new FlowLayout());
		frame_01.setSize(400,550);
		frame_01.add(title_label_01);
		frame_01.add(title_label_02);
		frame_01.add(title_label_03);
		frame_01.add(source_text_scrolling);
		frame_01.add(panel_01);
		frame_01.add(result_text_scrolling);
		frame_01.setVisible(true);

	}
}
