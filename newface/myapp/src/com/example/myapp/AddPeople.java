package com.example.myapp;

import android.content.Intent;
import android.graphics.Point;
import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.util.DisplayMetrics;
import android.view.Display;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.TextView;

public class AddPeople extends ActionBarActivity{
	 @Override
	    protected void onCreate(Bundle savedInstanceState) {
	        super.onCreate(savedInstanceState);
	        setContentView(R.layout.addpeople);
	        DisplayMetrics dm = new DisplayMetrics();
	    	
	    	Display display = getWindowManager().getDefaultDisplay();
	    	Point size = new Point();
	    	display.getSize(size);
	    	int width = size.x;
	    	int height = size.y;
	    	TextView tb = (TextView)findViewById(R.id.newfacedialog);
	    	tb.setPadding(width/16, height/25, 0, 0);
	    
	        Button btn1 = (Button)findViewById(R.id.done);
	        btn1.setOnClickListener(new OnClickListener(){

				@Override
				public void onClick(View v) {
					// TODO Auto-generated method stub
					Intent intent = new Intent(AddPeople.this,MainPage.class);
					startActivity(intent);
					
				}
	        	
	        	
	        });
	        
	        RadioButton rb1 = (RadioButton)findViewById(R.id.rb1);
	        RadioButton rb2 = (RadioButton)findViewById(R.id.rb2);
	        RadioButton rb3 = (RadioButton)findViewById(R.id.rb3);
	        RadioButton rb4 = (RadioButton)findViewById(R.id.rb4);
	        RadioButton rb5 = (RadioButton)findViewById(R.id.rb5);
	        GRadioGroup rg = new GRadioGroup();
	        rg.addrb(rb1);
	        rg.addrb(rb2);
	        rg.addrb(rb3);
	        rg.addrb(rb4);
	        rg.addrb(rb5);
	        
	       
	       
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

}

