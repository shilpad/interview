package shilpa.example.firstapp;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class MyFirstActivity extends Activity {
	public final static String EXTRA_MESSAGE = "com.example.myapp.MESSAGE";
	public static final String PREFS_NAME = "MyPrefsFile";

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
    }
    
    /** Called when the user selects the Send button */
    public void sendMessage (View view) {   	
    	Intent intent = new Intent (this, DisplayMessageActivity.class);
    	EditText editText = (EditText) findViewById (R.id.edit_message);
    	String message = editText.getText().toString();
    	intent.putExtra (EXTRA_MESSAGE, message);
    	
    	   // We need an Editor object to make preference changes.
        // All objects are from android.context.Context
        //SharedPreferences settings = getSharedPreferences(PREFS_NAME, 0);
        
    	startActivity (intent);
    }
}