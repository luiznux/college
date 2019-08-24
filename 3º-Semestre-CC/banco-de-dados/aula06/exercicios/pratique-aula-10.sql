CREATE TABLE Departamento(
    Cod_Depto INTEGER NOT NULL,
    Nome_Dep VARCHAR(20) NOT NULL,
    PRIMARY KEY(Cod_Depto)
);

CREATE TABLE Funcionario(
    Cod_Funci INTEGER NOT NULL,
    Nome_Func VARCHAR(20) NOT NULL,
    Salario INTEGER NOT NULL,
    Cod_Depto INTEGER NOT NULL,
    PRIMARY KEY(Cod_Funci),
    FOREIGN KEY(Cod_Depto)REFERENCES Departamento(Cod_Depto) 
    );

CREATE TABLE Projeto(
    Cod_Proj INTEGER NOT NULL,
    Nome_Proj VARCHAR(20) UNIQUE,
    Duracao INTEGER NOT NULL,
    PRIMARY KEY(Cod_Proj)
    );

 
CREATE TABLE Func_Projeto(
    Cod_Funci INTEGER NOT NULL,
    Cod_Proj  INTEGER NOT NULL,
    Horas_trab INTEGER CHECK(>=0),
    PRIMARY KEY(Cod_Funci,Cod_Proj),
    FOREIGN KEY(Cod_Depto)REFERENCES Departamento(Cod_Depto),
    FOREING KEY(Cod_Funci)REFERENCES Projeto(Cod_Funci)
    );



   
