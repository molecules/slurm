/*****************************************************************************\
 *  no_interconnect.c - Manage user task communications without an high-speed
 *	interconnect
 *****************************************************************************
 *  Copyright (C) 2002 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Kevin Tew <tew1@llnl.gov> et. al.
 *  UCRL-CODE-2002-040.
 *  
 *  This file is part of SLURM, a resource management program.
 *  For details, see <http://www.llnl.gov/linux/slurm/>.
 *  
 *  SLURM is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *  
 *  SLURM is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with ConMan; if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
\*****************************************************************************/

#include <sys/types.h>
#include <signal.h>

#include <src/slurmd/interconnect.h>
#include <src/slurmd/setenvpf.h>

int interconnect_node_init (void)
{
	return SLURM_SUCCESS;
}

int interconnect_node_fini (void)
{
	return SLURM_SUCCESS;
}

int interconnect_preinit (slurmd_job_t *job)
{
	return SLURM_SUCCESS;
}

int interconnect_init (slurmd_job_t *job)
{
	return SLURM_SUCCESS;
}

int interconnect_attach (slurmd_job_t *job, int taskid) 
{
	return SLURM_SUCCESS;
}

int interconnect_fini (slurmd_job_t *job)
{
	return SLURM_SUCCESS;
}

int interconnect_postfini (slurmd_job_t *job)
{
	/*
	 *  Kill all processes in the job's session
	 */
	if (job->smgr_pid) {
		debug2("Sending SIGKILL to pgid %lu", 
			(unsigned long) job->smgr_pid); 
		kill(-job->smgr_pid, SIGKILL);
	} else
		debug("Job %u.%u: Bad pid valud %lu", job->jobid, 
		      job->stepid, (unsigned long) job->smgr_pid);

	return SLURM_SUCCESS;
}


