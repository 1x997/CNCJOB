package com.example.server2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

import android.os.Handler;
import android.os.Message;

public class Serverthread extends Thread {

	private Handler handler;
	private MainActivity ctx;
	private ServerSocket serverSocket;
	public static final int SERVERPORT = 6000;
	private BufferedReader in;
	@Override
	public void run() {
		Socket socket = null;
		try {

			serverSocket = new ServerSocket(SERVERPORT);

		} catch (IOException e) {

			e.printStackTrace();
		}

		while (!Thread.currentThread().isInterrupted()) {
			try {
				
				socket = serverSocket.accept();
				CommunicationThread commThread = new CommunicationThread(socket,this.handler);
				new Thread(commThread).start();

				
			} catch (IOException e) {
				e.printStackTrace();
			}
			
		
		}

	}

	public Serverthread(MainActivity ctx){
		this.ctx=ctx;
		this.handler=ctx.getHandler();

	}

}

class CommunicationThread implements Runnable {
	private Handler handler;
	private Socket clientSocket;
	private BufferedReader input;
	public CommunicationThread(Socket clientSocket,Handler handler) {
		this.handler=handler;
		this.clientSocket = clientSocket;
	}
	
	public void run() {
		try {
				this.input = new BufferedReader(new InputStreamReader(this.clientSocket.getInputStream()));
				String read = input.readLine();
				input.close();
				clientSocket.close();
				Message message = Message.obtain();
				message.obj=read;
				handler.sendMessage(message);
				
				
				Message message2 = Message.obtain();
				message2.obj="empty";
				handler.sendMessageDelayed(message2, 5000);
				


			} catch (IOException e) {
				e.printStackTrace();
			}
		
	}
}

