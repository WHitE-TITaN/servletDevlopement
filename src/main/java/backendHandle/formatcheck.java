package backendHandle;
import java.io.IOException;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.RequestDispatcher;
import javax.servlet.annotation.WebServlet;
import javax.servlet.ServletException;
import javax.servlet.http.HttpSession;

import java.io.PrintWriter;

@WebServlet("/login")
public class formatcheck extends HttpServlet {
  public formatcheck() {
    super();
  }

  @Override
  protected void doPost(HttpServletRequest request, HttpServletResponse response)
          throws ServletException, IOException {
      
      String name = request.getParameter("name");
      String email = request.getParameter("email");
      response.setContentType("text/html");

      HttpSession session = request.getSession();
      session.setAttribute("servletDispatchFileFrom", "formatcheck.java");

      RequestDispatcher dispatcher = request.getRequestDispatcher("index.jsp");
      PrintWriter out = response.getWriter();
      
      out.println("<h1>Format Check Servlet : welcome : " + name +"</h1>");
      out.println("<p>email: " + email + "</p>");
      System.out.println("Format check servlet was called successfully!");

      dispatcher.include(request, response);
  }
}