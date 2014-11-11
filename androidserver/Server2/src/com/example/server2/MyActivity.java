package com.example.server2;


import android.app.Activity;
import android.app.Fragment;
import android.graphics.Bitmap;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.*;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

public class MyActivity extends Activity {

	private Handler handler;
	public Serverthread serverthread;
	public TextView  showmessage;

	public Handler getHandler(){
		return this.handler;
	}

	//	private final Runnable updateMessgae= new Runnable() 
	//    {
	//        public void run() 
	//        {
	//        	
	//			    showmessage=((TextView)findViewById(R.id.message));
	//				showmessage.setText("SOME BODY COME IN");
	//				showmessage.setTextColor(Color.parseColor("#FF0000"));
	//				
	//				
	//				showmessage.setText("NO body");
	//				showmessage.setTextColor(Color.parseColor("#00CC00"));
	//         
	//        }
	//    };


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		handler=new Handler(){
			public void handleMessage(Message msg){
				Bitmap message=(Bitmap)msg.obj;//
//				Log.i("get from thread", message);

				ImageView image=(ImageView)findViewById(R.id.imageView);

				image.setImageBitmap(message);

//				showmessage=((TextView)findViewById(R.id.message));
//				if(message.contains("empty")){
//					showmessage.setText("NO body");
//					showmessage.setTextColor(Color.parseColor("#00CC00"));
//
//				}else{
//
//					showmessage.setText("SOME BODY COME IN");
//					showmessage.setTextColor(Color.parseColor("#FF0000"));
//
//				}

				//  		

				//  				showmessage=((TextView)findViewById(R.id.message));
				//  				showmessage.setText("SOME BODY COME IN");
				//  				showmessage.setTextColor(Color.parseColor("#FF0000"));


				//  				showmessage.setText("NO body");
				//  				showmessage.setTextColor(Color.parseColor("#00CC00"));

			}
		};
	}

	public void startsocket(View v) {
		serverthread =new Serverthread(this);
		serverthread.start();
		Log.i("socket", "start socket server");
		((Button)findViewById(R.id.startsocket)).setEnabled(false);

	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {

		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	/**
	 * A placeholder fragment containing a simple view.
	 */
	public static class PlaceholderFragment extends Fragment {

		public PlaceholderFragment() {
		}

		@Override
		public View onCreateView(LayoutInflater inflater, ViewGroup container,
				Bundle savedInstanceState) {
			View rootView = inflater.inflate(R.layout.fragment_main, container,
					false);
			return rootView;
		}
	}

}
