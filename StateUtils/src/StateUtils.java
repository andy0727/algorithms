import javax.swing.JEditorPane;
import javax.swing.JFrame;
import java.util.LinkedHashMap;
import java.util.Map;

public class StateUtils extends JFrame{
  //create an static immutable hashmap maps state full name to abbr.
  private static final LinkedHashMap<String,String> nametoAbbr;
  static{
	  nametoAbbr=new LinkedHashMap<String,String>();
	  nametoAbbr.put("Alabama", "AL");
	  nametoAbbr.put("Alaska", "AK");
	  nametoAbbr.put("Arizona", "AZ");
	  nametoAbbr.put("Arkansas", "AR");
	  nametoAbbr.put("California", "CA");
	  //...
  }  
  
  //inverse the previous map since keys and values are unique
  private static final LinkedHashMap<String,String> abbrtoName;
  static{
	  abbrtoName=new LinkedHashMap<String,String>();
	  for(Map.Entry<String,String> entry: nametoAbbr.entrySet())
		  abbrtoName.put(entry.getValue(), entry.getKey());
  }
  
	
  //
  // Generates an HTML select list that can be used to select a specific
  // U.S. state.
  //
  public static String createStateSelectList()
  {
	StringBuilder html= new StringBuilder();
	html.append("<select name=\"state\">\n");
	for (String state: nametoAbbr.keySet()){
		html.append("<option value=\""
						+state+"\">"
						+state+"</option>\n");
	}
	html.append("</select>\n");
    return html.toString();
  }

  //
  // Parses the state from an HTML form submission, converting it to
  // the two-letter abbreviation.
  //
  public static String parseSelectedState(String s){
    	return nametoAbbr.get(s);
  }

  //
  // Displays the full name of the state specified by the two-letter code.
  //
  public static String displayStateFullName(String abbr){
	  return abbrtoName.get(abbr);
  }
  
  //Create a simple HTML to test the functions 
  void start(){
	  String html;
		  
	  html="<html><head><title>Simple Page</title></head>";
	  html+="<body bgcolor='#777779'><hr/><font size=50>This is Html content</font><hr/>"; 
	  html+=createStateSelectList()+"<br>";
	  html+=parseSelectedState("Alabama")+"<br>";
	  html+=displayStateFullName("AL")+"<br>";
	  html+="</body></html>"; 
	  JEditorPane ed1=new JEditorPane("text/html",html); 
	  add(ed1); 
	  setVisible(true); 
	  setSize(600,600); 
	  setDefaultCloseOperation(EXIT_ON_CLOSE); 
  }
  //Main to run the test.
  public static void main(String []args)
  {
	  new StateUtils().start();
  }
}
