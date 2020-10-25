package com.azhar.utsmercusuar;

import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.design.widget.BottomNavigationView;
import android.support.design.widget.CoordinatorLayout;
import android.support.v4.app.Fragment;
import android.support.v7.app.AppCompatDelegate;
import android.support.design.widget.NavigationView;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.MenuItem;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Toast;

import com.azhar.utsmercusuar.fragment.FacebookFragment;
import com.azhar.utsmercusuar.fragment.Instagram;
import com.azhar.utsmercusuar.fragment.Linkedin;
import com.azhar.utsmercusuar.fragment.Youtube;

public class HomeKuActivity extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener {

    private BottomNavigationView bottomNavigationView;
    private static final int MODE_DARK = 1;
    private static final int MODE_LIGHT = 0;


    private BottomNavigationView.OnNavigationItemSelectedListener mOnNavigationItemSelectedListener
            = new BottomNavigationView.OnNavigationItemSelectedListener() {

        @Override
        public boolean onNavigationItemSelected(@NonNull MenuItem item) {
            Fragment fragment;
            switch (item.getItemId()) {
                case R.id.navigationMyProfile:
                    Intent intentpe = new Intent(HomeKuActivity.this, Pengalaman.class);
                    startActivity(intentpe);
                    return true;
                case R.id.navigationMyCourses:
                    Intent intent = new Intent(HomeKuActivity.this, ScrollingActivity.class);
                    startActivity(intent);
                    return true;
                case R.id.navigationHome:
                    return true;
                case  R.id.navigationSearch:
                    Intent intent2 = new Intent(HomeKuActivity.this, Pendidikan.class);
                    startActivity(intent2);
                    return true;
                case  R.id.navigationMenu:
                    DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
                    drawer.openDrawer(GravityCompat.START);
                    return true;
            }
            return false;
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setDarkMode(getWindow());



        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);


        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.addDrawerListener(toggle);
        toggle.syncState();

        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);

        bottomNavigationView = findViewById(R.id.navigation);
        bottomNavigationView.setOnNavigationItemSelectedListener(mOnNavigationItemSelectedListener);
//
        CoordinatorLayout.LayoutParams layoutParams = (CoordinatorLayout.LayoutParams) bottomNavigationView.getLayoutParams();
        layoutParams.setBehavior(new BottomNavigationBehavior());

        bottomNavigationView.setSelectedItemId(R.id.navigationHome);

        //handling floating action menu
        findViewById(R.id.floatingActionButton).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
                drawer.openDrawer(GravityCompat.START);
            }
        });

    }

    @Override
    public void onBackPressed() {
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        } else {
            super.onBackPressed();
        }
    }


    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        // Handle navigation view item clicks here.
        int id = item.getItemId();

        if (id == R.id.nav_camera) {
            // Handle the camera action
        } else if (id == R.id.nav_gallery) {

        } else if (id == R.id.nav_slideshow) {

        } else if (id == R.id.nav_manage) {

        } else if (id == R.id.nav_share) {

        } else if (id == R.id.nav_dark_mode) {
            //code for setting dark mode
            //true for dark mode, false for day mode, currently toggling on each click
            DarkModePrefManager darkModePrefManager = new DarkModePrefManager(this);
            darkModePrefManager.setDarkMode(!darkModePrefManager.isNightMode());
            AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
            recreate();

        }

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }

    //create a seperate class file, if required in multiple activities
    public void setDarkMode(Window window){
//        if(new DarkModePrefManager(this).isNightMode()){
//            AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_YES);
//            changeStatusBar(MODE_DARK,window);
//        }else{
//            AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
//            changeStatusBar(MODE_LIGHT,window);
//        }
        AppCompatDelegate.setDefaultNightMode(AppCompatDelegate.MODE_NIGHT_NO);
        changeStatusBar(MODE_LIGHT,window);
    }
    public void changeStatusBar(int mode, Window window){
        if(Build.VERSION.SDK_INT>= Build.VERSION_CODES.M){
            window.addFlags(WindowManager.LayoutParams.FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS);
            window.setStatusBarColor(this.getResources().getColor(R.color.contentStatusBar));
            //Light mode
            if(mode==MODE_LIGHT){
                window.getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_LIGHT_STATUS_BAR);
            }
        }
    }
    public void activityFacebook(View View){
        //startActivity(new Intent(this,.class));
        Fragment fragment = new FacebookFragment();
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.drawer_layout, fragment, fragment.getClass().getSimpleName()).addToBackStack(null).commit();

        Toast.makeText(this, "Facebook Click Bro..", Toast.LENGTH_SHORT).show();
    }

    public void activityInstagram(View View){
        //startActivity(new Intent(this,.class));
        Fragment fragment = new Instagram();
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.drawer_layout, fragment, fragment.getClass().getSimpleName()).addToBackStack(null).commit();

        Toast.makeText(this, "Instagram Click Bro..", Toast.LENGTH_SHORT).show();
    }

    public void activityLinkedin(View View){
        //startActivity(new Intent(this,.class));
        Fragment fragment = new Linkedin();
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.drawer_layout, fragment, fragment.getClass().getSimpleName()).addToBackStack(null).commit();

        Toast.makeText(this, "Linkedin Click Bro..", Toast.LENGTH_SHORT).show();
    }
    public void activityYoutube(View View){
        //startActivity(new Intent(this,.class));
        Fragment fragment = new Youtube();
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.drawer_layout, fragment, fragment.getClass().getSimpleName()).addToBackStack(null).commit();

        Toast.makeText(this, "Youtube Click Bro..", Toast.LENGTH_SHORT).show();
    }
}
