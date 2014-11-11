package com.example.myapp;

import android.app.Activity;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class MyActivity extends Activity {
    /**
     * Called when the activity is first created.
     */

    private Handler handler;
    public Serverthread serverthread;
    public TextView showmessage;


    public Handler getHandler(){
        return this.handler;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        handler=new Handler(){
            public void handleMessage(Message msg){
                Bitmap message=(Bitmap)msg.obj;//
//				Log.i("get from thread", message);
                ImageView image=(ImageView)findViewById(R.id.imageView);
                image.setImageBitmap(message);
            }
        };




    }


    public void startsocket(View v) {
        serverthread =new Serverthread(this);
        serverthread.start();
        Log.i("socket", "start socket server");
        ((Button)findViewById(R.id.startsocket)).setEnabled(false);

    }




}
