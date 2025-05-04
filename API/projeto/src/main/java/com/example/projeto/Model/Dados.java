package com.example.projeto.Model;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.PrePersist;
import lombok.Getter;
import lombok.NoArgsConstructor;

@Entity
@Getter
@NoArgsConstructor
public class Dados {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE)
    private int id;
    private String horario;
    private Double nivel;

    public void setId(int id) {
        this.id = id;
    }

    public String formatador()
    {
        LocalDateTime agora = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
        return agora.format(formatter);
    }

    @PrePersist
    public void setHorarioAutomatico() {

        this.horario = formatador(); 
    }

    public void setHorario(String horario) {
        this.horario = horario;
    }

    public void setNivel(Double nivel) {
        this.nivel = nivel;
    }

    public Dados(String horario, int id, Double nivel) {
        this.horario = horario;
        this.id = id;
        this.nivel = nivel;
    }

    @Override
    public String toString() {
        return "Dados [id=" + id + ", horario=" + horario + ", nivel=" + nivel + " cm ]";
    }
}
