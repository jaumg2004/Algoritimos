import math

# Dados do problema
p0 = 1.01e5  # Pa
V0 = 0.0225  # m^3
p2 = 2 * p0
V2 = 2 * V0

# Constantes
R = 8.314  # J/(mol·K)
n = 1.00  # mol

# (a) Trabalho total durante o ciclo
T2 = p2 * V2 / (n * R)
W_iso_bc = n * R * T2 * math.log(V2 / V0)
W_iso_cd = p2 * (V2 - V0)
W_total = W_iso_bc + W_iso_cd

# (b) Energia adicionada em forma de calor durante o percurso abc
Q_abc = W_iso_bc

# (c) Eficiência do ciclo
efficiency = W_total / Q_abc

# (d) Eficiência de uma máquina de Carnot
Tb = p0 * V0 / (n * R)  # Temperatura em b
Td = p2 * V2 / (n * R)  # Temperatura em d
efficiency_carnot = 1 - Tb / Td

# Resultados
print("(a) Trabalho total durante o ciclo:", W_total, "Joules")
print("(b) Energia adicionada em forma de calor durante o percurso abc:", Q_abc, "Joules")
print("(c) Eficiência do ciclo:", efficiency)
print("(d) Eficiência de uma máquina de Carnot:", efficiency_carnot)
