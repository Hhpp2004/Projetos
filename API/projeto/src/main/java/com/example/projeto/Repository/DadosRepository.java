package com.example.projeto.Repository;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.example.projeto.Model.Dados;

@Repository
public interface DadosRepository extends JpaRepository<Dados, Integer>{
    
}
