package com.azhar.utsmercusuar.fragment;

import android.arch.lifecycle.ViewModelProviders;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import com.azhar.utsmercusuar.R;

public class FacebookFragment extends Fragment {

    private FacebookViewModel mViewModel;

    public static FacebookFragment newInstance() {
        return new FacebookFragment();
    }

    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container,
                             @Nullable Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.facebook_fragment, container, false);

        String url = "https://www.facebook.com/lexchannel17";
        WebView view = (WebView) rootView.findViewById(R.id.webView);
        view.getSettings().setJavaScriptEnabled(true);
        view.loadUrl(url);
        view.setWebViewClient(new WebViewClient());
        return rootView ;
        //return inflater.inflate(R.layout.facebook_fragment, container, false);
    }

    @Override
    public void onActivityCreated(@Nullable Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        mViewModel = ViewModelProviders.of(this).get(FacebookViewModel.class);
        // TODO: Use the ViewModel
    }

}