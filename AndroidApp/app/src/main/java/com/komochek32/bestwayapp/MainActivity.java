package com.komochek32.bestwayapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }

    public void selectCompany(View v){
        Intent intent = new Intent(this, CompanySelect.class);
        startActivity(intent);
    }

    public void selectLocation(View v){

    }

    public void selectType(View v){

    }

    public void selectDate(View v){

    }



    //C++ support


    /*
      A native method that is implemented by the 'native-lib' native library,
      which is packaged with this application.
     */

    // Used to load the 'native-lib' library on application startup.
    /*static {
        System.loadLibrary("native-lib");
    }

    public void goToC(View v){
        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
    }
    public native String stringFromJNI();
    */
}
