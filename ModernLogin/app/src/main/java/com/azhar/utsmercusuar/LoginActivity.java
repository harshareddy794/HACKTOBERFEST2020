package com.azhar.utsmercusuar;

import android.content.Intent;
import android.os.Build;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;


public class LoginActivity extends AppCompatActivity {
    EditText editTextEmail ,editTextPassword; //Deklarasi object dari class EdiText
    String text1 ,text2;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //for changing status bar icon colors
        if(Build.VERSION.SDK_INT>= Build.VERSION_CODES.M){
            getWindow().getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_LIGHT_STATUS_BAR);
        }
        setContentView(R.layout.activity_login);
    }

    public void onLoginClick(View view){
        editTextEmail = (EditText)findViewById(R.id.editTextEmail);
        editTextPassword = (EditText) findViewById(R.id.editTextPassword);
        text1 = editTextEmail.getText().toString();
        text2 = editTextPassword.getText().toString();

        //Kondisi jika username dan password benar maka akan menampilkan pesan text toast
        //Login sukses dan masuk ke activity 2
        if ((text1.contains("admin@admin.com"))&&((text2.contains("admin")))) {
            Toast.makeText(this, "Login Sukses", Toast.LENGTH_SHORT).show();
            Intent intent = new Intent(LoginActivity.this, HomeKuActivity.class);
            startActivity(intent);
        }

        else if ((text1.matches("")||text2.matches("")))
          /*
          Atau jika input text 1 dan text 2 kosong
           */
        {
            //Maka akan menampilkan pesan text toast
            Toast.makeText(this, "Isikan Username dan Password", Toast.LENGTH_SHORT).show();

        }

        else {
            //jika kedua kondisi diatas tidak memenuhi

            Toast.makeText(this, "Login Gagal /Username Password Salah", Toast.LENGTH_SHORT).show();
        }
    }
    public void onRegisterClick(View View){
        startActivity(new Intent(this,RegisterActivity.class));
        overridePendingTransition(R.anim.slide_in_right,R.anim.stay);

    }
}
