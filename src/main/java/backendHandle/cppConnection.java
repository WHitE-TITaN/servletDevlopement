package backendHandle;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/cpp")
public class cppConnection extends HttpServlet{
  
  @Override
  protected void doGet(HttpServletRequest request, HttpServletResponse response)
          throws ServletException, IOException {

    ProcessBuilder pb = new ProcessBuilder("C:\\Users\\dk488\\Documents\\GitHub\\servletDevlopement\\src\\bin\\server.exe");
    pb.redirectErrorStream(true);
    Process process = pb.start();


    BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
    StringBuilder output = new StringBuilder();
    String line;


    while ((line = reader.readLine()) != null) {
        output.append(line).append("<br>");
    }

    response.setContentType("text/html");
    PrintWriter out = response.getWriter();
    out.println("<h2>Output from C++:</h2>");
    out.println(output.toString());
  }
}