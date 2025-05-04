package com.example.projeto.Controller;

import java.net.URI;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.example.projeto.Model.Dados;
import com.example.projeto.Repository.DadosRepository;

import lombok.AllArgsConstructor;

@RestController
@AllArgsConstructor
@RequestMapping("/api")
@CrossOrigin(origins = "*")
public class DadosController {

    @Autowired
    final private DadosRepository dr;

    @PostMapping("/nivel")
    public ResponseEntity<String> receberNivel(@RequestBody Dados dados) {
        if (dados != null) {
            System.out.println("\n" + dados.toString() + "\n");
            dr.save(dados);
            URI location = URI.create("/api/nivel/" + dados.getId());
            return ResponseEntity.created(location).build();
        }
        else
        {
            return ResponseEntity.badRequest().build();
        }
    }
}
