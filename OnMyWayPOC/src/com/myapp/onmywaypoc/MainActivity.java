package com.myapp.onmywaypoc;

import java.io.IOException;
import java.util.List;
import java.util.Locale;

import com.google.android.maps.GeoPoint;

import android.app.Activity;
import android.content.Context;
import android.location.Address;
import android.location.Geocoder;
import android.os.Bundle;
import android.view.Menu;
import android.widget.Toast;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		searchLocationByName (getApplicationContext(), "420 S Springer Road, Los Altos, CA 94024");
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	public static Address searchLocationByName(Context context, String locationName){
	    Geocoder geoCoder = new Geocoder(context, Locale.getDefault());
	    GeoPoint gp = null;	
	    Address ad = null;
	    try {
	        List<Address> addresses = geoCoder.getFromLocationName(locationName, 1);
	        for(Address address : addresses){
	            gp = new GeoPoint((int)(address.getLatitude() * 1E6), (int)(address.getLongitude() * 1E6));
	            address.getAddressLine(1);
	            ad = address;
	            Toast.makeText(context, ad.getAddressLine(0),
	                    Toast.LENGTH_SHORT).show();
	        }
	    } catch (IOException e) {
	        e.printStackTrace();
	    }
	    return ad;
	}
}
