package com.komochek32.bestwayapp;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.ListView;

public class CompanySelect extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_company_select);

        displayText();
    }


    String[] compNames = new String[]{"Company 1", "Company 2", "Company 3"};

    private void displayText(){

        ListAdapter adapter = new ArrayAdapter<>(this, R.layout.support_simple_spinner_dropdown_item, compNames);
        ListView lv = findViewById(R.id.company_dynamic);
        lv.setAdapter(adapter);

    }



}
