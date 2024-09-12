# $NetBSD$

BUILDLINK_TREE+=	or-tools

.if !defined(OR_TOOLS_BUILDLINK3_MK)
OR_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.or-tools+=	or-tools>=99bugfix
BUILDLINK_PKGSRCDIR.or-tools?=		../../wip/or-tools

.include "../../wip/HiGHS/buildlink3.mk"
.include "../../wip/scip/buildlink3.mk"
.include "../../wip/ThirdParty-Mumps/buildlink3.mk"
.include "../../wip/nauty/buildlink3.mk"
.include "../../wip/ThirdParty-ASL/buildlink3.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../math/openblas/buildlink3.mk"
.include "../../math/coinmp/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.endif	# OR_TOOLS_BUILDLINK3_MK

BUILDLINK_FILES.or-tools+=	bin/assignment_groups_mip
BUILDLINK_FILES.or-tools+=	bin/assignment_groups_sat
BUILDLINK_FILES.or-tools+=	bin/assignment_linear_sum_assignment
BUILDLINK_FILES.or-tools+=	bin/assignment_min_flow
BUILDLINK_FILES.or-tools+=	bin/assignment_mip
BUILDLINK_FILES.or-tools+=	bin/assignment_sat
BUILDLINK_FILES.or-tools+=	bin/assignment_task_sizes_mip
BUILDLINK_FILES.or-tools+=	bin/assignment_task_sizes_sat
BUILDLINK_FILES.or-tools+=	bin/assignment_teams_mip
BUILDLINK_FILES.or-tools+=	bin/assignment_teams_sat
BUILDLINK_FILES.or-tools+=	bin/assumptions_sample_sat
BUILDLINK_FILES.or-tools+=	bin/balance_min_flow
BUILDLINK_FILES.or-tools+=	bin/basic_example
BUILDLINK_FILES.or-tools+=	bin/bfs_directed
BUILDLINK_FILES.or-tools+=	bin/bfs_one_to_all
BUILDLINK_FILES.or-tools+=	bin/bfs_undirected
BUILDLINK_FILES.or-tools+=	bin/bin_packing_mip
BUILDLINK_FILES.or-tools+=	bin/binpacking_problem_sat
BUILDLINK_FILES.or-tools+=	bin/bool_or_sample_sat
BUILDLINK_FILES.or-tools+=	bin/channeling_sample_sat
BUILDLINK_FILES.or-tools+=	bin/clone_model_sample_sat
BUILDLINK_FILES.or-tools+=	bin/cocktail_hour
BUILDLINK_FILES.or-tools+=	bin/cp_is_fun_cp
BUILDLINK_FILES.or-tools+=	bin/cp_is_fun_sat
BUILDLINK_FILES.or-tools+=	bin/cp_sat_example
BUILDLINK_FILES.or-tools+=	bin/cutting_stock
BUILDLINK_FILES.or-tools+=	bin/dag_constrained_shortest_path_sequential
BUILDLINK_FILES.or-tools+=	bin/dag_multiple_shortest_paths_one_to_all
BUILDLINK_FILES.or-tools+=	bin/dag_multiple_shortest_paths_sequential
BUILDLINK_FILES.or-tools+=	bin/dag_shortest_path_one_to_all
BUILDLINK_FILES.or-tools+=	bin/dag_shortest_path_sequential
BUILDLINK_FILES.or-tools+=	bin/dag_simple_constrained_shortest_path
BUILDLINK_FILES.or-tools+=	bin/dag_simple_multiple_shortest_paths
BUILDLINK_FILES.or-tools+=	bin/dag_simple_shortest_path
BUILDLINK_FILES.or-tools+=	bin/dijkstra_all_pairs_shortest_paths
BUILDLINK_FILES.or-tools+=	bin/dijkstra_directed
BUILDLINK_FILES.or-tools+=	bin/dijkstra_one_to_all
BUILDLINK_FILES.or-tools+=	bin/dijkstra_sequential
BUILDLINK_FILES.or-tools+=	bin/dijkstra_undirected
BUILDLINK_FILES.or-tools+=	bin/earliness_tardiness_cost_sample_sat
BUILDLINK_FILES.or-tools+=	bin/facility_lp_benders
BUILDLINK_FILES.or-tools+=	bin/fzn-cp-sat
BUILDLINK_FILES.or-tools+=	bin/graph_coloring
BUILDLINK_FILES.or-tools+=	bin/integer_programming_example
BUILDLINK_FILES.or-tools+=	bin/interval_sample_sat
BUILDLINK_FILES.or-tools+=	bin/knapsack
BUILDLINK_FILES.or-tools+=	bin/lagrangian_relaxation
BUILDLINK_FILES.or-tools+=	bin/linear_programming_example
BUILDLINK_FILES.or-tools+=	bin/literal_sample_sat
BUILDLINK_FILES.or-tools+=	bin/mathopt_info
BUILDLINK_FILES.or-tools+=	bin/minimal_jobshop_cp
BUILDLINK_FILES.or-tools+=	bin/minimal_jobshop_sat
BUILDLINK_FILES.or-tools+=	bin/mip_var_array
BUILDLINK_FILES.or-tools+=	bin/multiple_knapsack_mip
BUILDLINK_FILES.or-tools+=	bin/multiple_knapsack_sat
BUILDLINK_FILES.or-tools+=	bin/no_overlap_sample_sat
BUILDLINK_FILES.or-tools+=	bin/non_linear_sat
BUILDLINK_FILES.or-tools+=	bin/nqueens_cp
BUILDLINK_FILES.or-tools+=	bin/nqueens_sat
BUILDLINK_FILES.or-tools+=	bin/nurses_cp
BUILDLINK_FILES.or-tools+=	bin/nurses_sat
BUILDLINK_FILES.or-tools+=	bin/optional_interval_sample_sat
BUILDLINK_FILES.or-tools+=	bin/rabbits_and_pheasants_cp
BUILDLINK_FILES.or-tools+=	bin/rabbits_and_pheasants_sat
BUILDLINK_FILES.or-tools+=	bin/ranking_sample_sat
BUILDLINK_FILES.or-tools+=	bin/reified_sample_sat
BUILDLINK_FILES.or-tools+=	bin/root_a_tree
BUILDLINK_FILES.or-tools+=	bin/rooted_tree_paths
BUILDLINK_FILES.or-tools+=	bin/sat_runner
BUILDLINK_FILES.or-tools+=	bin/schedule_requests_sat
BUILDLINK_FILES.or-tools+=	bin/search_for_all_solutions_sample_sat
BUILDLINK_FILES.or-tools+=	bin/simple_cp_program
BUILDLINK_FILES.or-tools+=	bin/simple_glop_program
BUILDLINK_FILES.or-tools+=	bin/simple_knapsack_program
BUILDLINK_FILES.or-tools+=	bin/simple_lp_program
BUILDLINK_FILES.or-tools+=	bin/simple_ls_program
BUILDLINK_FILES.or-tools+=	bin/simple_max_flow_program
BUILDLINK_FILES.or-tools+=	bin/simple_min_cost_flow_program
BUILDLINK_FILES.or-tools+=	bin/simple_mip_program
BUILDLINK_FILES.or-tools+=	bin/simple_pdlp_program
BUILDLINK_FILES.or-tools+=	bin/simple_routing_program
BUILDLINK_FILES.or-tools+=	bin/simple_sat_program
BUILDLINK_FILES.or-tools+=	bin/solution_hinting_sample_sat
BUILDLINK_FILES.or-tools+=	bin/solve
BUILDLINK_FILES.or-tools+=	bin/solve_and_print_intermediate_solutions_sample_sat
BUILDLINK_FILES.or-tools+=	bin/solve_with_time_limit_sample_sat
BUILDLINK_FILES.or-tools+=	bin/step_function_sample_sat
BUILDLINK_FILES.or-tools+=	bin/stigler_diet
BUILDLINK_FILES.or-tools+=	bin/stop_after_n_solutions_sample_sat
BUILDLINK_FILES.or-tools+=	bin/time_indexed_scheduling
BUILDLINK_FILES.or-tools+=	bin/tsp
BUILDLINK_FILES.or-tools+=	bin/tsp_circuit_board
BUILDLINK_FILES.or-tools+=	bin/tsp_cities
BUILDLINK_FILES.or-tools+=	bin/tsp_cities_routes
BUILDLINK_FILES.or-tools+=	bin/tsp_distance_matrix
BUILDLINK_FILES.or-tools+=	bin/vector_bin_packing
BUILDLINK_FILES.or-tools+=	bin/vrp
BUILDLINK_FILES.or-tools+=	bin/vrp_breaks
BUILDLINK_FILES.or-tools+=	bin/vrp_capacity
BUILDLINK_FILES.or-tools+=	bin/vrp_drop_nodes
BUILDLINK_FILES.or-tools+=	bin/vrp_global_span
BUILDLINK_FILES.or-tools+=	bin/vrp_initial_routes
BUILDLINK_FILES.or-tools+=	bin/vrp_pickup_delivery
BUILDLINK_FILES.or-tools+=	bin/vrp_pickup_delivery_fifo
BUILDLINK_FILES.or-tools+=	bin/vrp_pickup_delivery_lifo
BUILDLINK_FILES.or-tools+=	bin/vrp_resources
BUILDLINK_FILES.or-tools+=	bin/vrp_routes
BUILDLINK_FILES.or-tools+=	bin/vrp_solution_callback
BUILDLINK_FILES.or-tools+=	bin/vrp_starts_ends
BUILDLINK_FILES.or-tools+=	bin/vrp_time_windows
BUILDLINK_FILES.or-tools+=	bin/vrp_with_time_limit
BUILDLINK_FILES.or-tools+=	bin/vrptw_store_solution_data

BUILDLINK_TREE+=	-or-tools
