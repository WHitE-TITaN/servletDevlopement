package dataExchange;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


@WebServlet("/exchangeData")
  public class setupConnection extends HttpServlet{

    @Override
      protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException{

        PrintWriter write = response.getWriter();
        RequestDispatcher newBatch = request.getRequestDispatcher("index.jsp");
        
      }
  }
