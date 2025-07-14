import com.sun.net.httpserver.Request;
import java.io.IOException;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.RequestDispatcher;
import javax.servlet.annotation.WebServlet;
import javax.servlet.ServletException;

import java.io.PrintWriter;

@WebServlet("/login")
public class formatcheck extends HttpServlet {
  public formatcheck() {
    super();
  }

  @Override
  protected void doPost(HttpServletRequest request, HttpServletResponse response)
          throws ServletException, IOException {

      response.setContentType("text/html");

      RequestDispatcher dispatcher = request.getRequestDispatcher("index.html");
      PrintWriter out = response.getWriter();
      
      out.println("<h1>Format Check Servlet</h1>");
      System.out.println("Format check servlet was called successfully!");

      dispatcher.include(request, response);
  }
}